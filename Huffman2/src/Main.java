import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;


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
	
	public static void main(String[] args) throws IOException{
		File file = new File("/Users/sonynka/Documents/HTW/Algorithms/Huffman2/input.txt");
		int[] freq = getFrequencies(file);
		int size = freq.length;
		
		HuffmanMinHeap minHeap = new HuffmanMinHeap(data, freq, size);
		minHeap.buildMinHeap();
		
		MinHeapNode root = minHeap.buildHuffmanTree();
		int[] arr = new int[100];
		int top = 0;
		minHeap.printCodes(root, arr, top);
		
		System.out.println("done");
		
	}
	
}
