import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.print("Height: ");
        int height = input.nextInt();

        System.out.println();

        for (int i = 1; i <= height; i++) {

            int starCount = (i * 2) - 1;
            int spaceCount = height - i + 1;

            for (int j = 0; j < spaceCount; j++)
                System.out.print(" ");

            for (int j = 0; j < starCount; j++)
                System.out.print("*");

            System.out.println();
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < height; j++)
                System.out.print(" ");

            System.out.println("*");
        }

        input.close();
    }
}