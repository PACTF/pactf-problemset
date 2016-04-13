import java.util.Random;
import java.util.Scanner;
import java.util.InputMismatchException;
import java.io.File;
import java.io.IOException;

public class RandomGame {
  public static void main(String... args) throws IOException {
    Scanner sc = new Scanner(System.in);
    System.out.print("What is your name? ");
    String name = sc.next();
    // I read some article on the internet where someone using a new Random()
    // and system time seed was easily pwnd, so all we have to do is generate
    // our "own" random data based off what the user inputs. As long as we
    // hash what they put in, there's no way they'll be able to control what
    // the random number puts out!

    // If we hash the hash, it'll be doubly difficult to figure out, right?
    Random rng = new Random(customHash("" + customHash(name)));

    System.out.print("Guess my number (between 0 and 50): ");
    try {
      int number = rng.nextInt(51);
      int guess = sc.nextInt();
      if (guess == number) {
        System.out.println("Wow, you got it!");
        giveFlag();
      }
      else {
        System.out.printf("Nope, it was %d.\n", number);
      }
    }
    catch (InputMismatchException e) {
      System.out.println("That's not a number!");
    }
  }

  private static void giveFlag() throws IOException {
    Scanner sc = new Scanner(new File("flag.txt"));
    System.out.println("Your flag is:");
    System.out.println(sc.nextLine());
  }

  // This function is private and the hashing algorithm is really long and
  // complicated (java said so!), so there's no way anybody can figure out
  // what the seed will be!
  private static int customHash(String s) {
    // TODO: Write long and complicated hashing algorithm
    return s.hashCode();
  }
}
