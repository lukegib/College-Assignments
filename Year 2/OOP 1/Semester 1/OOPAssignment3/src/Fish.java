public class Fish extends Animal{

    boolean hasGills;
    boolean hasFins;
    boolean swims;

    /**
     * Constructor for objects of class Bird
     */
    public Fish()
    {
        super(); //calls the constructor of its superclass  - Animal
        hasGills = true; //all the subclasses of Fish inherit this property and value
        hasFins = true; //all the subclasses of Fish inherit this property and value
        swims = true; //all the subclasses of Fish inherit this property and value
    }

    /**
     * move method overrides the move method
     * inherited from superclass Animal
     */
    @Override // good programming practice to use @Override to denote overridden methods
    public void move(int distance){
        if(swims){
            System.out.printf("I swim %d metres \n", distance);
        }else {
            System.out.printf("I am a fish but cannot swim.\n");
        }
    }

    /**
     * 'getter' method for the hasFins field - NOT USED
     */
    public boolean hasFins(){
        return hasFins;
    }

    /**
     * 'getter' method for the hasGills field - NOT USED
     */
    public boolean hasGills(){
        return hasGills;
    }

}
