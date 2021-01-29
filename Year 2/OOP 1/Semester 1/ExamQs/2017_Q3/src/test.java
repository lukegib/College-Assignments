public class test {

    public static void main(String[] args){

        PostBox postbox = new PostBox();

        postbox.post(new Letter("Galway"));
        postbox.post(new Letter("Dublin"));
        postbox.post(new Letter("Kerry"));
        postbox.post(new Letter("Galway"));
        postbox.post(new Letter("Galway"));
        postbox.post(new Letter("Galway"));

        MailBag galwayBag = new MailBag("Galway");
        MailBag dublinBag = new MailBag("Dublin");
        MailBag kerryBag = new MailBag("Kerry");

        postbox.empty(galwayBag);
        postbox.empty(dublinBag);
        postbox.empty(kerryBag);

        galwayBag.printItems();
        dublinBag.printItems();
        kerryBag.printItems();

    }
}
