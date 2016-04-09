import java.util.Scanner;
import java.lang.Math;

public class problem1 {
    public static void main(String args[]) 
    {
    	int flag[] = {116,104,101,102,108,97,103,105,115,100,111,110,116,112,117,116,112,97,115,115,119,111,114,100,115,105,110,106,97,118,97};
    	String password = "ThisIsAVeryComplexPasswordThatYouCouldNeverGuess";
    	System.out.print("What is the password? ");
    	Scanner sc = new Scanner(System.in);
    	String userInput = sc.nextLine();
    	String theFlag = "";
    	for(int i : flag){
    		theFlag+=(char)i;
    	}
    	if(userInput.equals(password)){
    		System.out.println("Golly gosh darnit. You got Me!");
    		System.out.println(theFlag);
    	}
    	else{
    		System.out.println("disaPOINTED! (try again)");
    	}
    }
}