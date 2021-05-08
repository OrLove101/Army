import java.lang.reflect.Array;
import java.util.*;

public class MainArmy {
    public static void main(String[] args) {
        Warlock warlock = new Warlock("Warlock");
        Necromancer necro = new Necromancer("Necrom");
        Soldier soldier = new Soldier("Cap");

        System.out.println(warlock + " vs " + soldier);
        System.out.println(necro);

        Demon demon = warlock.summon("Monkey");

        System.out.println(soldier + " vs " + demon);

        soldier.attack(necro);

        System.out.println(necro);

        soldier.attack(demon);

        System.out.println(necro);

        System.out.println(demon + " vs " + soldier);

        soldier.attack(demon);

        System.out.println(demon + " vs " + soldier);

//        Rogue berrog = new Rogue("Vasya") {
//            @Override
//            public String toString() {
//                return "Im POLIMORFUS ANONIM";
//            }
//        };
//
//        System.out.println(berrog);
//
//        int[] a;
//        int b[];
//
//        a = new int[10]; // [0, 0, 0, 0]
//        a[0] = 1;
//        Arrays.fill(a, 5);
//
//
//
//        b = new int[] {1, 2, 3, 5, 6 };
//
//        int[] c = {1, 2, 3, 4};
//
//        System.out.println("a: " + Arrays.toString(a));
//
//        ArrayList<Integer> list = new ArrayList<Integer>();
//
//        List<Integer> lst = new ArrayList<Integer>(); // convenient
//
//        lst.add(1);
//        lst.add(2);
//        lst.add(3);
//
//        lst = Collections.unmodifiableList(lst);
//
//        System.out.println(lst.toString());
//
//        lst.remove(2);
//        lst.set(1, 5);
//
//        System.out.println(lst.toString());
//
//        LinkedList<Boolean> linkedList = new LinkedList<>();
//
//        linkedList.add(false);
//        linkedList.add(true);
//        linkedList.addFirst(true);
//
//        System.out.println(linkedList.toString());
//
//        for ( int i = 0; i < linkedList.size(); i++ ) {
//            boolean element = linkedList.get(i);
//            if ( !element ) {
//                linkedList.remove(i);
//                System.out.println("removed " + i);
//            }
//        }
//
//        System.out.println(linkedList.toString());
//
//
//        Queue<Integer> intQueue = new PriorityQueue<>();
//
//        intQueue.add(1);
//
//        for ( int i = 0; i < intQueue.size(); i++ ) {
//            intQueue.poll();
//        }
//
//
//        Deque<Integer> intDeque = new ArrayDeque<>();
//
//        intDeque.addLast(1);
//        intDeque.add(2);
//
//
//        HashMap<Integer, String> map = new HashMap<>();
//
//        map.put(1, "Hello");
//        map.put(2, "World");
//
//        System.out.println(map.toString());
//
//        HashSet<String> hashSet = new HashSet<>();
//
//        hashSet.add("Hello");
//
//        System.out.println(hashSet.contains("Hello"));
    }
}