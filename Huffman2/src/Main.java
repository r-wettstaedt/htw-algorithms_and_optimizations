import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.math.BigInteger;
import java.util.HashMap;


public class Main {
	
	//public static char[] data = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' '};
	public static char[] data = {'a', 'b', 'c', 'd', 'e', 'f'};
	
	
	private static int[] getFrequencies(File file) throws IOException {
		int[] freq = new int[data.length];
		InputStream input = new BufferedInputStream(new FileInputStream(file));
		try {
			int c;
			int counter = 0;
			while ((c = input.read()) != -1) {
				char ch = (char)c;
				counter++;
				for(int i = 0; i < data.length; i++){
					if(data[i] == ch){
						freq[i]++;
					}
				}
			}
		} finally {
			input.close();
		}
		
		return freq;
	}
	
	public static void compressFile(File inputFile, File outputFile, HashMap<Character, String> codeTable) throws IOException{
		InputStream inStream = new BufferedInputStream(new FileInputStream(inputFile));
		try {
			String outputString = "";
			int c;
			while ((c = inStream.read()) != -1) {
				char ch = (char)c;
				String code = codeTable.get(ch);
				outputString += code;
			}
			
			//fill the last unfilled spots of the last bit with zeros
			int bitsLeftToFill = outputString.length()%8;
			if(bitsLeftToFill > 0){
				for(int i = 0; i < 8-bitsLeftToFill; i++){
					outputString += "0";
				}
			}
			
			
			BigInteger big = new BigInteger(outputString, 2);
			byte[] b = big.toByteArray();
			
			//drop the most significant bit - no need for sign
			if (b[0] == 0) {
			    byte[] tmp = new byte[b.length - 1];
			    System.arraycopy(b, 1, tmp, 0, tmp.length);
			    b = tmp;
			}
			
			FileOutputStream fos = new FileOutputStream(outputFile);
			fos.write(b);
			fos.close();
			
			System.out.println("converted");
		} finally {
			inStream.close();
		}
		
	}
	
	public static void decompressFile(File toDecompress, File decompressed, HashMap<Character, String> codeTable){
		//TODO
		//Decompress file
	}
	
	public static void main(String[] args) throws IOException{
		//get letter frequencies from file
		File originalFile = new File("input2.txt");
		int[] freq = getFrequencies(originalFile);
		int size = freq.length;
		
		HuffmanMinHeap minHeap = new HuffmanMinHeap(data, freq, size);
		minHeap.buildMinHeap();
		
		MinHeapNode root = minHeap.buildHuffmanTree();
		
		//get codes
		int[] arr = new int[100];
		int top = 0;
		minHeap.printCodes(root, arr, top);
		HashMap<Character, String> codeTable = new HashMap<Character, String>();
		minHeap.getCodes(root, arr, top, codeTable);
		
		File compressedFile = new File("output");
		compressFile(originalFile, compressedFile, codeTable);
		
		File decompressedFile = new File("decompressedFile.txt");
		decompressFile(compressedFile, decompressedFile, codeTable);
		
		
		System.out.println("done");
		
	}
	
}
