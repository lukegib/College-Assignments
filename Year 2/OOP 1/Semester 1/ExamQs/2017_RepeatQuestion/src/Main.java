public class Main {

    public static void main(String[] args){

        Train train = new Train(80);

        Passenger passenger = new Passenger("Sheila Hughes");
        Ticket ticket = new Ticket(1, 10);
        passenger.addTicket(ticket);
        train.addPassenger(passenger);

        passenger = new Passenger("Seamus Sullivan");
        ticket = new Ticket(2,7);
        passenger.addTicket(ticket);
        train.addPassenger(passenger);

        passenger = new Passenger("Camile Lafferty");
        train.addPassenger(passenger);

        passenger = new Passenger("Liam Toohey");
        ticket = new Ticket(2, 7);
        passenger.addTicket(ticket);
        train.addPassenger(passenger);

        int firstclass = train.numPassengers(1);
        System.out.println("Number of first class passengers: " + firstclass);

        int secondclass = train.numPassengers(2);
        System.out.println("Number of second class passengers: " + secondclass);

        double totalFares = train.getTotalFares();
        System.out.println("Total fares collected: " + totalFares);

    }
}
