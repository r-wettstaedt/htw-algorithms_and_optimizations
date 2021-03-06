import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.math.BigInteger;
import java.nio.file.Files;
import java.util.HashMap;
import java.util.Set;


public class Main {
	
	public static char[] data = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' '};
	
	
	private static int[] getFrequencies(File file) throws IOException {
		int[] freq = new int[data.length];
		InputStream input = new BufferedInputStream(new FileInputStream(file));
		try {
			int c;
			while ((c = input.read()) != -1) {
				char ch = (char)c;
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
	
	public static int compressFile(File inputFile, File outputFile, HashMap<Character, String> codeTable) throws IOException{
		InputStream inStream = new BufferedInputStream(new FileInputStream(inputFile));
		try {
			String outputString = "";
			int c;
			while ((c = inStream.read()) != -1) {
				char ch = (char)c;
				String code = codeTable.get(ch);
				outputString += code;
			}
			
			//fill the last unfilled spots of the last byte with zeros
			int bitsLeftToFill = 8 - outputString.length()%8;
			if(bitsLeftToFill > 0){
				for(int i = 0; i < bitsLeftToFill; i++){
					outputString += "0";
				}
			}
			
			//convert the string to bitearray
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
			
			System.out.println("File compressed");
			return bitsLeftToFill;
			
		} finally {
			inStream.close();
		}
		
	}
	
	public static void decompressFile(File toDecompress, File decompressed, HashMap<Character, String> codeTable, int finalZeros) throws IOException{
		//revert the codetables keys and values
		HashMap<String, Character> revCodeTable = revertCodeTable(codeTable);
		
		//read all bytes from file
		byte[] fileBytes = Files.readAllBytes(toDecompress.toPath());
		InputStream inStream = new BufferedInputStream(new FileInputStream(toDecompress));
		try {
			String outputString = "";
			String readCode = "";
			String code = "";
			
			for(int i = 0; i < fileBytes.length; i++){
				byte by = fileBytes[i];
				String byteStr = Integer.toBinaryString(by & 0xFF);
				
				if(byteStr.length() < 8){
					int bitsToComplete = 8 - byteStr.length();
					while(bitsToComplete > 0){
						//get the zeros on the most left bits
						byteStr = "0" + byteStr;
						bitsToComplete--;
					}
				}
				
				code += byteStr;
				
			}
			
			//do not decompress the last zeros used to fill the byte
			if(finalZeros > 0){
				code = code.substring(0, code.length() - finalZeros);
			}
				
			for(int i = 0; i < code.length(); i++){
				char c = code.charAt(i);
				readCode += c;
				if(revCodeTable.containsKey(readCode)){
					outputString += revCodeTable.get(readCode);
					readCode = "";
				}
			}
		
			FileWriter out = new FileWriter(decompressed);
			out.write(outputString);
			out.close();
			
			System.out.println("File decompressed");
		} finally {
			inStream.close();
		}
		
		
	}
	
	//Revert the keys and values in the codetable
	public static HashMap<String, Character> revertCodeTable(HashMap<Character, String> origCodeTable){
		HashMap<String, Character> revCodeTable = new HashMap<String, Character>();
		
		Set<Character> set = origCodeTable.keySet();
		Object[] keys = set.toArray();
		for(int i = 0; i < keys.length; i++){
			char key = (char)keys[i];
			String value = origCodeTable.get(key);
			revCodeTable.put(value, key);
		}
		
		return revCodeTable;
	}
	
	public static void main(String[] args) throws IOException{
		//get letter frequencies from file
		File originalFile = new File("input.txt");
		int[] freq = getFrequencies(originalFile);
		int size = freq.length;
		
		HuffmanMinHeap minHeap = new HuffmanMinHeap(data, freq, size);
		minHeap.buildMinHeap();
		
		MinHeapNode root = minHeap.buildHuffmanTree();
		
		//get codes
		int[] arr = new int[100];
		int top = 0;
		HashMap<Character, String> codeTable = new HashMap<Character, String>();
		minHeap.getCodes(root, arr, top, codeTable);
		
		//compress and decompress
		File compressedFile = new File("compressedFile");
		int finalZeros = compressFile(originalFile, compressedFile, codeTable);
		
		File decompressedFile = new File("decompressedFile.txt");
		decompressFile(compressedFile, decompressedFile, codeTable, finalZeros);
		
		
	}
	
}
