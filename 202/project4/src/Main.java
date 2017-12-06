
/**
 * Author: Sam Gomena
 * Class: CS202 Fall 2017
 * Instructor: Karla Fant
 */

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {

        Tree tree = new Tree(Menu.readData());
        tree.display();

        DLL dll = new DLL(); // Create new list to house our orders.
        Menu.print("Welcome to CS202_Eatz.", "\n\n");

        do {
            switch (Menu.showOptions(Menu.stdOps, "What would you like to do")) {
                case -1:
                    Menu.print("Please select a valid menu option and try again");
                    break;
                case 1:
                    Menu.print("Starting New Order...");
                    String chosenRestaurant =
                            Menu.showAndGetOptions(
                                    Menu.restaurants(false),
                            "Here are the available restaurants:",
                            "mins");
                    if(chosenRestaurant == null) {
                        Menu.print("Sorry, we didn't retrieve that.\nPlease try again.");
                        break;
                    }
                    String[] itemWithPrice =
                            Menu.showAndGetOptions(
                                    Menu.menuItems(chosenRestaurant),
                                    ("What do you want to order from " + chosenRestaurant.split(" ")[0] + "?"),
                            "").split("\\$");
                    if(itemWithPrice.length == 1) {
                        Menu.print("Sorry, we didn't retrieve that.\nPlease try again.");
                        break;
                    }
                    String item = itemWithPrice[0];
                    String price = itemWithPrice[1];
                    if(dll.addOrder(Menu.getRestaurant(chosenRestaurant), chosenRestaurant, item, Float.parseFloat(price))) {
                        Menu.print("Your order of " + item + "has been added.\nTotal orders: " + dll.getOrderNums());
                    } else {
                        Menu.print("Sorry, we were not able to insert your order, please try again.");
                    }
                    break;
                case 2:
                    int orders = dll.display();
                    if(orders == 0) {
                        Menu.print("It looks like you don't have any orders yet.\nPress '1' to change that.");
                    } else {
                        Menu.print("Total orders: " + orders);
                    }
                    break;
                case 3:
                    System.out.println("Sorry this action is not supported yet.");
                    break;
                case 4:
                    Menu.print("Note: We only take whole bitcoins.");
                    // TODO: Add functionality for project 5.
                    Menu.done();
                    break;
                default:
                    Menu.print("Sorry, we didn't retrieve that.\nPlease try again.");
            }
        } while (Menu.notDone());
        dll.removeAll();
    }
}