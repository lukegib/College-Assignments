public class Trout extends Fish{

    boolean isSpikey;
    boolean isEdible;
    boolean laysEggsUpriver;
    String name;

    public Trout(String name){
        super();
        isSpikey = true;
        isEdible = true;
        laysEggsUpriver = true;
        colour = "brown";
        this.name = name;
    }

    //getName returns the Name of the animal... Used in toString() method
    public String getName(){return name;}


    @Override
    public String toString(){
        String string = "\n*** Trout ***\n";
        string += "\nName: " + name;
        string += "\nColor: " + colour;
        string+= "\nHas_Skin: " + hasSkin;
        string+= "\nBreathes: " + breathes;
        string+= "\nSwims: " + swims;
        string+= "\nHas_Gills: " + hasGills;
        string+= "\nHas_Fins: " + hasFins;
        string += "\nSpikey: " + isSpikey;
        string += "\nEdible: " + isEdible;
        string += "\nLays_Eggs_Upriver: " + laysEggsUpriver;
        return string;
    }

    @Override
    public boolean equals(java.lang.Object object){
        //if the object is null OR it isn't a Trout object - returns false
        if (object == null || !(object instanceof Trout)){
            return false;
        }

        //The object is casted to a Canary object
        Trout testTrout = (Trout)object;

        //If they equal - return true
        if(testTrout.getName() == name){
            return true;
        }

        return false; //default equals
    }
}
