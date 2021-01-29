public class tester {

    String input = "4+3-12";
    char[] array = input.toCharArray();


    public void checkme() {

        for (int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
            if(Character.isDigit(array[i]) && Character.isDigit(array[i+1])){
                System.out.println("The above character wont work as double digit!");
            }
            else{
                System.out.println("This looks ok to me!");
            }
        }

    }
}
