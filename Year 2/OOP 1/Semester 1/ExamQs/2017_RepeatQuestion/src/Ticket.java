public class Ticket {

    int tier;
    int cost;

    public Ticket(int tier, int cost){
        this.tier = tier;
        this.cost = cost;
    }

    public int getTicketTier() {
        return tier;
    }

    public void setTicketTier(int ticketClass) {
        this.tier = tier;
    }

    public int getCost() {
        return cost;
    }

    public void setCost(int cost) {
        this.cost = cost;
    }
}
