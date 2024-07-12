import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class WumpusWorld {
    private int size;
    private Pair<Integer, Integer> agentPosition;
    private List<Pair<Integer, Integer>> pitLocations;
    private Pair<Integer, Integer> wumpusLocation;
    private Pair<Integer, Integer> treasureLocation;
    private boolean arrowAvailable;
    private boolean gameOver;

    public WumpusWorld() {
        size = 4;
        agentPosition = new Pair<>(0, 0);
        pitLocations = generateRandomLocations();
        wumpusLocation = generateRandomLocation(List.of(agentPosition), pitLocations);
        treasureLocation = generateRandomLocation(List.of(agentPosition, wumpusLocation), pitLocations);
        arrowAvailable = true;
        gameOver = false;
    }

    private List<Pair<Integer, Integer>> generateRandomLocations() {
        List<Pair<Integer, Integer>> locations = new ArrayList<>();
        Random rd = new Random();
        for (int i = 0; i < size; ++i) {
            locations.add(new Pair<>(rd.nextInt(size), rd.nextInt(size)));
        }
        return locations;
    }

    private Pair<Integer, Integer> generateRandomLocation(List<Pair<Integer, Integer>> exclude1, List<Pair<Integer, Integer>> exclude2) {
        Random rd = new Random();
        Pair<Integer, Integer> location;
        do {
            location = new Pair<>(rd.nextInt(size), rd.nextInt(size));
        } while (exclude1.contains(location) || exclude2.contains(location));
        return location;
    }

    private boolean checkAdjacent(Pair<Integer, Integer> position, Pair<Integer, Integer> target) {
        int x = position.getFirst();
        int y = position.getSecond();
        List<Pair<Integer, Integer>> adjacentRooms = List.of(new Pair<>(x - 1, y), new Pair<>(x + 1, y),
                new Pair<>(x, y - 1), new Pair<>(x, y + 1));
        return adjacentRooms.contains(target);
    }

    private List<String> checkPercept() {
        List<String> percept = new ArrayList<>();
        int x = agentPosition.getFirst();
        int y = agentPosition.getSecond();
        if (checkAdjacent(agentPosition, wumpusLocation)) {
            percept.add("Stench");
        }
        if (checkAdjacent(agentPosition, treasureLocation)) {
            percept.add("Glitter");
        }
        for (Pair<Integer, Integer> pitLocation : pitLocations) {
            if (checkAdjacent(agentPosition, pitLocation)) {
                percept.add("Breeze");
            }
        }
        return percept;
    }

    private void move(String direction) {
        if (direction.equals("up")) {
            agentPosition = new Pair<>(Math.max(0, agentPosition.getFirst() - 1), agentPosition.getSecond());
        } else if (direction.equals("down")) {
            agentPosition = new Pair<>(Math.min(size - 1, agentPosition.getFirst() + 1), agentPosition.getSecond());
        } else if (direction.equals("left")) {
            agentPosition = new Pair<>(agentPosition.getFirst(), Math.max(0, agentPosition.getSecond() - 1));
        } else if (direction.equals("right")) {
            agentPosition = new Pair<>(agentPosition.getFirst(), Math.min(size - 1, agentPosition.getSecond() + 1));
        }
        if (pitLocations.contains(agentPosition)) {
            gameOver = true;
            System.out.println("You fell into a pit! Game over.");
        } else if (agentPosition.equals(wumpusLocation)) {
            gameOver = true;
            System.out.println("You were eaten by the Wumpus! Game over.");
        } else if (agentPosition.equals(treasureLocation)) {
            gameOver = true;
            System.out.println("You found the treasure and escaped the cave! You win.");
        } else {
            System.out.println("Moved to room (" + agentPosition.getFirst() + ", " + agentPosition.getSecond() + ")");
            List<String> percept = checkPercept();
            System.out.print("Percept: ");
            for (String p : percept) {
                System.out.print(p + " ");
            }
            System.out.println();
        }
    }

    private void shootArrow() {
        if (arrowAvailable) {
            arrowAvailable = false;
            if (agentPosition.equals(wumpusLocation)) {
                gameOver = true;
                System.out.println("You killed the Wumpus with your arrow! You win.");
            } else {
                System.out.println("You missed the Wumpus with your arrow.");
            }
        } else {
            System.out.println("You don't have any arrows left.");
        }
    }

    public boolean isGameOver() {
        return gameOver;
    }

    public static void main(String[] args) {
        WumpusWorld game = new WumpusWorld();
        Scanner scanner = new Scanner(System.in);
        while (!game.isGameOver()) {
            System.out.print("Enter action (up, down, left, right, shoot): ");
            String action = scanner.next().toLowerCase();
            if (action.equals("shoot")) {
                game.shootArrow();
            } else if (action.equals("up") || action.equals("down") || action.equals("left") || action.equals("right")) {
                game.move(action);
            } else {
                System.out.println("Invalid action. Please enter up, down, left, right, or shoot.");
            }
        }
        scanner.close();
    }
}

class Pair<T1, T2> {
    private final T1 first;
    private final T2 second;

    public Pair(T1 first, T2 second) {
        this.first = first;
        this.second = second;
    }

    public T1 getFirst() {
        return first;
    }

    public T2 getSecond() {
        return second;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Pair<?, ?> pair = (Pair<?, ?>) obj;
        if (!first.equals(pair.first)) return false;
        return second.equals(pair.second);
    }

    @Override
    public int hashCode() {
        int result = first.hashCode();
        result = 31 * result + second.hashCode();
        return result;
    }
}
