public class Main {
    public static void main(String[] args) {
        String a = "test";
        String b = "test";
        String c = new String("test");
        String d = new String("test");

        System.out.println(c == d);
        System.out.println(a == b);
        System.out.println(a.equals(c));
        System.out.println(a ==c);
    }
}