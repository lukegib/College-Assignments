public class AnimalTest {

    public static void main(String[] args){
        AnimalTest test = new AnimalTest();
        test.testToString(); //test for toString method and the move method
        test.testEquals(); //test for the equal() method
    }

    public void testToString(){
        System.out.println("\n********** Test 1: Animal toString() method test ***********");
        Animal[] animals = new Animal[4]; //initialise a new Animal array
        animals[0] = new Canary("Roddy");
        animals[1] = new Ostrich("Leggy");
        animals[2] = new Shark("Jaws");
        animals[3] = new Trout("Slippy");

        for(Animal animal : animals){ //for loop to go through all array elements
            System.out.println(animal); //prints the toString() method
            animal.move(10); //prints the move method
        }

    }

    public void testEquals(){
        System.out.println("\n\n************ Test 2: Animal equals() method test ************\n");
        Animal[] animals = new Animal[4]; //initialise new Animal array
        animals[0] = new Canary("Canny");
        animals[1] = new Ostrich("Fluffy");
        animals[2] = new Shark("Teddy");
        animals[3] = new Trout("Ricky");

        for(Animal animal : animals){ //Nested for loops to go through the array twice, comparing each class
            for(Animal animal2 : animals){
                if(animal.equals(animal2)) {
                    System.out.println("Animal 1: a " + animal.getClass().getSimpleName() + " is EQUAL to Animal 2: a " + animal2.getClass().getSimpleName());
                }
            }
        }
    }
}
