public class order {

    int noOfPassengers;
    String startingLocation;
    String destination;
    String dateOfDeparture;
    String TimeOfDeparture;
    String dateOfArrival;
    String timeOfArrival;
    float fare;

    public order(int noOfPassengers, String startingLocation, String destination, String dateOfDeparture, String TimeOfDeparture, String dateOfArrival, String timeOfArrival, float fare){
        this.noOfPassengers = noOfPassengers;
        this.startingLocation = startingLocation;
        this.destination = destination;
        this.dateOfDeparture = dateOfDeparture;
        this.TimeOfDeparture = TimeOfDeparture;
        this.dateOfArrival = dateOfArrival;
        this.timeOfArrival = timeOfArrival;
        this.fare = fare;
    }

    public int getNoOfPassengers() {
        return noOfPassengers;
    }

    public void setNoOfPassengers(int noOfPassengers) {
        this.noOfPassengers = noOfPassengers;
    }

    public String getStartingLocation() {
        return startingLocation;
    }

    public void setStartingLocation(String startingLocation) {
        this.startingLocation = startingLocation;
    }

    public String getDestination() {
        return destination;
    }

    public void setDestination(String destination) {
        this.destination = destination;
    }

    public String getDateOfDeparture() {
        return dateOfDeparture;
    }

    public void setDateOfDeparture(String dateOfDeparture) {
        this.dateOfDeparture = dateOfDeparture;
    }

    public String getTimeOfDeparture() {
        return TimeOfDeparture;
    }

    public void setTimeOfDeparture(String timeOfDeparture) {
        TimeOfDeparture = timeOfDeparture;
    }

    public String getDateOfArrival() {
        return dateOfArrival;
    }

    public void setDateOfArrival(String dateOfArrival) {
        this.dateOfArrival = dateOfArrival;
    }

    public String getTimeOfArrival() {
        return timeOfArrival;
    }

    public void setTimeOfArrival(String timeOfArrival) {
        this.timeOfArrival = timeOfArrival;
    }

    public float getFare() {
        return fare;
    }

    public void setFare(float fare) {
        this.fare = fare;
    }
}
