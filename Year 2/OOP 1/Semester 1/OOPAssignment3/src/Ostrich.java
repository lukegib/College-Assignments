public class Ostrich extends Bird{

    boolean tall;
    boolean hasLongLegs;
    String name;

    public Ostrich(String name){
        super();
        this.name = name;
        tall = true;
        hasLongLegs = true;
        flies = false;
    }

    //getName returns the Name of the animal... Used in toString() method
    public String getName(){return name;}


    @Override
    public String toString(){
        String string = "\n*** Ostrich ***\n";
        string += "\nName: " + name;
        string += "\nColor: " + colour;
        string+= "\nHas_Skin: " + hasSkin;
        string+= "\nBreathes: " + breathes;
        string+= "\nHas_Feathers: " + hasFeathers;
        string+= "\nHas_Wings: " + hasWings;
        string+= "\nIs_Tall: " + tall;
        string+= "\nHas_Long_Legs: " + hasLongLegs;
        string += "\nFlies: " + flies;
        return string;
    }

    @Override
    public boolean equals(java.lang.Object object){
        //if the object is null OR it isn't an Ostrich object - returns false
        if (object == null || !(object instanceof Ostrich)){
            return false;
        }

        //The object is casted to an Ostrich object
        Ostrich testOstrich = (Ostrich)object;

        //If they equal - return true
        if(testOstrich.getName() == name){
            return true;
        }

        return false; //default equals
    }

}
