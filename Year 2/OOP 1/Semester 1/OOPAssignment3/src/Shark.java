public class Shark extends Fish {

    boolean bites;
    boolean isDangerous;
    String name;

    public Shark(String name){
        super();
        bites = true;
        isDangerous = true;
        this.name = name;
    }

    //getName returns the Name of the animal... Used in toString() method
    public String getName(){return name;}


    @Override
    public String toString(){
        String string = "\n*** Shark ***\n";
        string += "\nName: " + name;
        string += "\nColor: " + colour;
        string+= "\nHas_Skin: " + hasSkin;
        string+= "\nBreathes: " + breathes;
        string+= "\nSwims: " + swims;
        string+= "\nHas_Gills: " + hasGills;
        string+= "\nHas_Fins: " + hasFins;
        string += "\nBites: " + bites;
        string += "\nDangerous: " + isDangerous;
        return string;
    }

    @Override
    public boolean equals(java.lang.Object object){
        //if the object is null OR it isn't a Shark object - returns false
        if (object == null || !(object instanceof Shark)){
            return false;
        }

        //The object is casted to a Shark object
        Shark testShark = (Shark)object;

        //If they equal - return true
        if(testShark.getName() == name){
            return true;
        }

        return false; //default equals
    }
}
