import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

/*
 * Created on Mar 29, 2004
 *
 * Creates a HashTable on your Hard Disk Drive for Quick hashing of large files.
 */

/**
 * Compares two files and returns a file with all the differences.
 * 
 * @author Rick_Runowski
 */
public class HashIt {

	static List lst = new ArrayList();
	
   /**
	* HashIt takes a string and turns it into a semi-unique Hash value to   
    *    be used in narrowing the scope of searchable data sets and resolve    
    *    comparisons in shorter times.  Requires a string as input, and will   
    *    output a string variable that is actually a digit.
    *    
	* @param files
	* @param numfile
	* @param outfile
	* @return
	* @throws IOException
	*/
	public static boolean Hashit(String files[], int numfile, String outfile) throws IOException{
		BufferedReader f1;
		File f = new File(outfile);
		PrintWriter out = new PrintWriter(new FileWriter(f));
		String buffer;
		
		for(int c = 0; c < numfile; c++){
			f1 = new BufferedReader(new FileReader(files[c]));
		
			while((buffer = f1.readLine()) != null){
				buffer = buffer.trim();
				buffer = buffer.toUpperCase();
				
				if((lst != null)&& (lst.contains(buffer.trim()))){
				   lst.remove(buffer);
				}
				else{
					lst.add(buffer.trim());
					
				}
			}
			f1.close();
		}
		System.out.println(lst.size());
		Object t;
		
		// Output the remainder of the buffer to a file.
		for(int c = 0; c < lst.size(); c++){
			out.println(lst.get(c));
		}
		
		out.flush();
		return true;	
	}
	
	public static void main(String[] args) {
		long t2;
		long t1 = System.currentTimeMillis();
		
		try {
			Hashit(args, args.length, "./return.txt");
		} catch (IOException e) {
			e.printStackTrace();
		}
		t2 = System.currentTimeMillis();
		System.out.println("Test Complete in " + (t2 - t1) + "ms!");
	}
}
