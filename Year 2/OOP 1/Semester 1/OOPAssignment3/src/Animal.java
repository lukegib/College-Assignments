
/**
 * Write a description of class Animal here.
 *
 * @author (Ihsan Ullah)
 * @version (17 October 2018)
 */
public class Animal
{
    // instance variables - replace the example below with your own
    boolean hasSkin;
    boolean breathes;
    String colour;
    
    /**
     * Constructor for objects of class Animal
     */
    public Animal()
    {
        breathes = true; //all the subclasses of Animal inherit this property and value
        hasSkin = true; // all the subclasses of Animal inherit this property and value
        colour = "grey"; //all the subclasses of Animal inherit this property and value
    }
    /**
     * move method
     * param int distance - the distance the Animal should move
     * All subclasses inherit this method
     */
    public void move(int distance){
        System.out.printf("I move %d metres \n", distance);
    }
    
    /**
     * eat method
     * param Food food - food the Animal should eat
     * We haven't defined this yet
     * All subclasses inherit this method
     */
    public void eat(Food food){
        //TODO - leave this for now
    }
    
    /**
     * getter method for colour field
     * All subclasses inherit this method
     */
    public String getColour(){
        return colour;
    }
    
     /**
     * 'getter' method for haSkin field
     * All subclasses inherit this method
     */
    
    public boolean hasSkin(){
        return hasSkin;
    }
}
