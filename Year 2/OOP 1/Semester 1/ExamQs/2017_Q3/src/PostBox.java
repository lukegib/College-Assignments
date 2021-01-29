import java.util.ArrayList;

public class PostBox {

    ArrayList<Letter> kerryPost = new ArrayList<>();
    ArrayList<Letter> dublinPost = new ArrayList<>();
    ArrayList<Letter> galwayPost = new ArrayList<>();

    public PostBox() {
    }

    public void post(Letter letter){
        if(letter.getCounty().equalsIgnoreCase("kerry")){
            kerryPost.add(letter);
        }
        else if(letter.getCounty().equalsIgnoreCase("galway")){
            galwayPost.add(letter);
        }
        else if(letter.getCounty().equalsIgnoreCase("dublin")){
            dublinPost.add(letter);
        }
        else{System.out.println("Unknown address detected - Letter invalid.");}
    }

    public void empty(MailBag m){
        if(m.getCounty().equalsIgnoreCase("kerry")){
            for(Letter l: kerryPost){
                m.addMail(l);
            }
        }
        else if(m.getCounty().equalsIgnoreCase("galway")){
            for(Letter l: galwayPost){
                m.addMail(l);
            }
        }
        else{
            for(Letter l: dublinPost){
                m.addMail(l);
            }
        }
    }
}
