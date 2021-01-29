import java.util.ArrayList;

public abstract class PublicTransport {

    public ArrayList<Passenger> passOnBoard =  new ArrayList<>();
    int capacity;
    int i = 0;
    int fClassP = 0;
    int sClassP = 0;
    double totalFare = 0;

    public void addPassenger(Passenger passenger){
        if(passenger.getTicketPrice() != 0) {
            if (i < capacity) {
                passOnBoard.add(passenger);
                if(passenger.getTicketClass() == 1){fClassP+=1;}
                else{sClassP+=1;}
                i++;
            } else {
                System.out.println("Train full!");
            }
        }
    }

    public int numPassengers(int tier){
        if(tier == 1){
            return fClassP;
        }
        else if(tier == 2){
            return sClassP;
        }
        return 0;
    }

    public double getTotalFares(){
        for(Passenger p: passOnBoard){
            totalFare += p.getTicketPrice();
        }

        return totalFare;
    }

}
