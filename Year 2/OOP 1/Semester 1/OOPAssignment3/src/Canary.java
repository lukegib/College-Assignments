
public class Canary extends Bird
{
    String name; // the name of this Canary

    public Canary(String name)
    {
        super(); // call the constructor of the superclass Bird
        this.name = name;
        colour = "yellow"; // this overrides the value inherited from Bird
    }

    //getName returns the Name of the animal... Used in toString() method
    public String getName(){return name;}

    @Override // good programming practice to use @Override to denote overridden methods
    public void sing(){
        System.out.println("tweet tweet tweet");
    }

    @Override
    public String toString(){
        String string = "\n***Canary ***\n";
        string += "\nName: " + name;
        string += "\nColor: " + colour;
        string+= "\nHas_Skin: " + hasSkin;
        string+= "\nBreathes: " + breathes;
        string+= "\nHas_Feathers: " + hasFeathers;
        string+= "\nHas_Wings: " + hasWings;
        string += "\nFlies: " + flies;
        return string;
    }

    
    /**
     * equals method defines how equality is defined between 
     * the instances of the Canary class
     * param Object
     * return true or false depending on whether the input object is 
     * equal to this Canary object
     */
    
    @Override
    public boolean equals(java.lang.Object object){
        //if the object is null OR it isn't a Canary object - returns false
        if (object == null || !(object instanceof Canary)){
            return false;
        }

        //The object is casted to a Canary object
        Canary testCanary = (Canary)object;

        //If they equal - return true
        if(testCanary.getName() == name){
            return true;
        }

        return false; //default equals
    }
}
