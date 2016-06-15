import java.util.HashMap;


public class HuffmanMinHeap {
	
	int heapSize;
	MinHeapNode[] nodeArray;
	
	public HuffmanMinHeap(char[] data, int[] freq, int size){
		heapSize = size;
		nodeArray = new MinHeapNode[heapSize];
		
		for(int i = 0; i < size; i++){
			nodeArray[i] = new MinHeapNode(data[i], freq[i]);
		}
	}
	
	private void minHeapify(int idx){
		int min = idx;
		int left = getLeft(idx);
		int right = getRight(idx);
		
		if(left < heapSize && nodeArray[left].freq < nodeArray[idx].freq){
			min = left;
		}
		
		if(right < heapSize && nodeArray[right].freq < nodeArray[min].freq){
			min = right;
		}
		
		if(min != idx){
			swapNodes(idx, min);
			minHeapify(min);
		}
		
	}
	
	private void swapNodes(int a, int b){
		MinHeapNode temp = nodeArray[a];
		nodeArray[a] = nodeArray[b];
		nodeArray[b] = temp;
	}
	
	private int getLeft(int idx){
		return 2 * idx + 1;
	}
	
	private int getRight(int idx){
		return 2 * idx + 2;
	}
	
	private int getParent(int idx){
		return (idx - 1)/2;
	}
	
	public void buildMinHeap(){
		for(int i = heapSize/2 - 1; i >= 0; i--){
			minHeapify(i);
		}
	}
	
	private boolean isGreaterOne(){
		return (heapSize > 1);
	}
	
	private MinHeapNode extractMin(){
		MinHeapNode min = nodeArray[0];
		nodeArray[0] = nodeArray[heapSize-1];
		heapSize--;
		minHeapify(0);
		
		return min;
	}
	
	private void heapIncreaseKey(int idx, MinHeapNode node){
		if(node.freq < nodeArray[idx].freq){
			System.out.println("New key less than actual key");
		}
		
		nodeArray[idx] = node;
		
		while(idx > 1 && nodeArray[getParent(idx)].freq > nodeArray[idx].freq){
			swapNodes(idx, getParent(idx));
			idx = getParent(idx);
		}
	}
	
	
	private void insertNode(MinHeapNode node){
		
		heapSize++;
		nodeArray[heapSize-1] = new MinHeapNode();
		
		heapIncreaseKey(heapSize-1, node);
	}
	
	public MinHeapNode buildHuffmanTree(){
		MinHeapNode left, right, internal;
		
		while(isGreaterOne()){
			left = extractMin();
			right = extractMin();
			
			internal = new MinHeapNode('$', left.freq + right.freq);
			internal.left = left;
			internal.right = right;
			insertNode(internal);
		}
		
		return extractMin();
	}
	
	private boolean isLeaf(MinHeapNode node){
		return (node.left == null && node.right == null);
	}
	
	
	public void getCodes(MinHeapNode root, int arr[], int top, HashMap<Character, String> codeTable){
		
		if(root.left != null){
			arr[top] = 0;
			getCodes(root.left, arr, top + 1, codeTable);
		}
		
		if(root.right != null){
			arr[top] = 1;
			getCodes(root.right, arr, top + 1, codeTable);
		}
		
		if(isLeaf(root)){
			System.out.print(root.letter + ": ");
			printArr(arr, top);
			
			String code = "";
			for(int i = 0; i < top; i++){
				code += Integer.toString(arr[i]);
			}
			
			codeTable.put(root.letter, code);
		}
		
	}
	

	
	private void printArr(int arr[], int n){
		for(int i = 0; i < n; i++){
			System.out.print(arr[i]);
		}
		
		System.out.println();
	}
	
	
}
