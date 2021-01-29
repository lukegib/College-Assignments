import java.util.ArrayList;

public class MailBag {

    String county;
    ArrayList<Letter> mail = new ArrayList<>();

    public MailBag(String county) {
        this.county = county;
    }

    public String getCounty() {
        return county;
    }

    public void addMail(Letter letter){
        mail.add(letter);
    }

    public void printItems(){
        System.out.println("Mail for County: " + county);
        for(Letter l: mail){
            System.out.println(l);
        }
        System.out.println("\n");
    }
}
