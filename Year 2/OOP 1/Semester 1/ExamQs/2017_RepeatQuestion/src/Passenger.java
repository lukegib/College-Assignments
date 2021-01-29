public class Passenger {

    private String name;
    Ticket ticket = new Ticket(0, 0);

    public Passenger(String name) {
        this.name = name;
    }

    public void addTicket(Ticket ticket){
        this.ticket = ticket;
    }

    public int getTicketClass() {
        return ticket.getTicketTier();
    }

    public int getTicketPrice(){
        return ticket.getCost();
    }

}
