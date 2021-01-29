 /**
 * Customer class contains the data about a customer
 * firstName, LastName, emailAddress, customerId
 * It may also contain to the Customer's Shipping Addresses
 * I haven't implemented that here - but it seems like 
 * realistic piece of data to include
 */

public class Customer {
    private String firstName;
    private String surname;
    private String emailAddress;
    private final long customerId;
    
    public Customer(String firstName, String surname, String emailAddress){
        this.firstName = firstName;
        this.surname = surname;
        this.emailAddress = emailAddress;
        customerId  = makeCustomerId();
    }
    
    public long getId() {

        return customerId;
    }
    
    public String getFirstName() {

        return firstName;
    }

    public String getSurname() {
        
        return surname;
    }
    
    public String getEmailAddress() {

        return emailAddress;
    }
    
    
 /**
 * a method that obtains a customerId.
 * A real method of this type would make a call to a database
 * or database-backed system to to obtain a unique Id
 */
    private long makeCustomerId() {

        return (long)(Math.random() * 99999999999999L);
    }

    public void setFirstName(String first) {

        firstName = first;
    }

    public void setLastName(String last) {

        surname = last;
    }

    public void setEmailAddress(String emailAddress) {

        this.emailAddress = emailAddress;
    }

}
