package bytecode;

import java.util.LinkedList;

public final class Routine implements Comparable<Routine>{

	private static final String MAIN = "main";

	private static int ID = 1;

	private final int id;
	private final String name;
	private final LinkedList<Integer> data;

	public Routine(String name) {
		this.id = name.equalsIgnoreCase(MAIN) ? 0 : Routine.ID++;
		this.name = name;
		this.data = new LinkedList<>();
	}

	public int getId() {
		return id;
	}

	public String getName() {
		return name;
	}

	public LinkedList<Integer> getData() {
		return data;
	}

	@Override
	public String toString() {
		return "Routine{" +
				"id=" + id +
				", name='" + name + '\'' +
				", data=" + data +
				'}';
	}

	@Override
	public int compareTo(Routine o) {
		return Integer.compare(id, o.id);
	}
}
