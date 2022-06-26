
import java.util.Arrays;
import java.util.Scanner;

public class bankersalgorithm {

	static int procs;
	static int resources;
	static int[] units; // which == 1 is rfr if which == 2 unitsofeachrec
	static int[][] requestfromresource;
	static int[][] unitsofeachresource;
	static int[] available;
	static int[][] potential;
	static int[] sequance;
	static Boolean[] done;
	static Boolean deadlock;
	static Boolean[] unsafe;

	/// get rid of below
	/*
	 * static int procs =5 ;
	 * static int resources=3 ;
	 * static int [] units= {10,5,7} ; //which == 1 is rfr if which == 2
	 * unitsofeachrec
	 * static int[][] requestfromresource= {
	 * {7,5,3},
	 * {3,2,2},
	 * {9,0,2},
	 * {2,2,2},
	 * {4,3,3}
	 * };
	 * static int[][] unitsofeachresource = {
	 * {0,1,0},
	 * {2,0,0},
	 * {3,0,2},
	 * {2,1,1},
	 * {0,0,2}
	 * }; ;
	 * static int [] available;
	 * static int [][] potential;
	 * static Boolean [] done;
	 */
	/// get rid of above
	static void enterparams() {
		Scanner input = new Scanner(System.in);
		System.out.print("Enter number of processes");

		procs = Integer.parseInt(input.nextLine().replaceAll("[^0-9]", ""));
		System.out.println();
		System.out.print("Enter number of resources");
		resources = Integer.parseInt(input.nextLine().replaceAll("[^0-9]", ""));
		System.out.println();
		System.out.print("Enter number of units for resources (r0 to r" + String.valueOf(resources - 1) + "):");
		String inputs = input.nextLine().trim();
		System.out.println();
		growSize(inputs);
		requestfromresource = new int[procs][resources];
		int count = 0;
		while (count < procs) {
			System.out.print("Enter maximum number of units process p" + count
					+ " will request from each resource (r0 to r" + String.valueOf(resources - 1) + "):");
			inputs = input.nextLine().trim();
			dataimport2d(inputs, count, 1);
			System.out.println();
			count++;
		}

		System.out.println(Arrays.deepToString(requestfromresource).replace("], ", "]\n"));
		//////////////
		count = 0;
		unitsofeachresource = new int[procs][resources];
		while (count < procs) {
			System.out.print("Enter number of units of each resource (r0 to r" + String.valueOf(resources - 1)
					+ ") allocated to process p" + count);
			inputs = input.nextLine().trim();
			dataimport2d(inputs, count, 2);
			System.out.println();
			count++;
		}
		System.out.println(Arrays.deepToString(unitsofeachresource).replace("], ", "]\n"));
		input.close();
		/////////////////////////////////////////////////////////////////////////////////////////// format
		/////////////////////////////////////////////////////////////////////////////////////////// and
		/////////////////////////////////////////////////////////////////////////////////////////// print
		/////////////////////////////////////////////////////////////////////////////////////////// now

		makeavailablearray();
		System.out.println(Arrays.toString(available));
		makeunitsavailabletable();

	}

	static boolean checkSchedule() {
		int sequencedCount = 0, unsafeCount = 0;

		for (int i = 0; i < procs; i++) {

			if (done[i] == false && unsafe[i] == true) {
				unsafeCount++;
			}

			if (done[i] == true) {
				sequencedCount++;
			}

		} // end of the for

		if (unsafeCount + sequencedCount == procs && unsafeCount > 0) {
			System.out.println("Deadlock reached!");
			return false;

		} else if (unsafeCount + sequencedCount == procs && unsafeCount == 0) {

			System.out.print("Safe Sequence: ");
			for (int g = 0; g < procs; g++) {

				System.out.print("P" + sequance[g] + " ");

			} // endofforloop
			System.out.println();
			return false;
		} else {
			return true;

		}
	}// end of the function

	static boolean checkmead(int index) {
		System.out.print("Checking: <");
		for (int a = 0; a < resources; a++) {
			System.out.print(" " + potential[index][a] + " ");
		}
		System.out.print("> <= <");
		for (int a = 0; a < resources; a++) {
			System.out.print(" " + available[a] + " ");
		}
		System.out.print("> :");
		for (int i = 0; i < resources; i++) {
			if (potential[index][i] > available[i])
				return false;
		}
		return true;
	}

	static void bankersalgo() {
		int count = 0;
		String rs = "";
		String sideelement1 = "";
		String sideelement2 = "";
		unsafe = new Boolean[procs];

		while (count < procs) {
			unsafe[count] = false;
			count++;
		}
		done = new Boolean[procs];
		sequance = new int[procs];
		count = 0;
		while (count < procs) {
			done[count] = false;
			count++;
		}
		count = 0;
		/////////////////////////
		int donechecker = 0;
		int donecounter = 0;
		int comparicounter = 0;

		while (checkSchedule()) {
			for (int i = 0; i < procs; i++) {

				// System.out.println(count);
				if (done[i] == false) {
					if (checkmead(i)) {
						System.out.println("p" + i + " safely sequanced");

						done[i] = true;
						donecounter++;
						sequance[donecounter - 1] = i;
						for (int q = 0; q < resources; q++) {
							available[q] += unitsofeachresource[i][q];
						}
						for (int y = 0; y < procs; y++) {
							unsafe[y] = false;
						}
					} else {
						System.out.println("p" + i + " could not be sequanced");
						unsafe[i] = true;
					}

				} // end of big IF
					//

				//////// check to see if we are fully done////////////////

			} /// for loop ends/////////////////////////////////////////////////////////////
		} /// while loop ends/////////////////////////////////////////////////////////////

	}/// end of bankers
		/// algo/////////////////////////////////////////////////////////////

	static void makeunitsavailabletable() {
		System.out.println("        Units   Available");
		System.out.println("------------------------");
		int count = 0;
		while (count < resources) {
			System.out.println("r" + count + "      " + units[count] + "         " + available[count] + "        ");
			count++;
		}

		System.out.println("        Max claim                       Current                         Potential");
		String rs = "        ";
		String oldrs = "";
		count = 0;
		while (count < resources) {
			rs = rs + "r" + count + "      ";
			count++;
		}
		count = 0;
		oldrs = rs;
		while (count < resources - 1) { // System.out.println(rs);
			rs = rs + oldrs;
			count++;
		}
		System.out.println(rs);
		// System.out.println(" r0 r1 r2 r0 r1 r2 r0 r1 r2");

		System.out
				.println("------------------------------------------------------------------------------------------");
		count = 0;
		rs = "";
		int count2 = 0;
		while (count < procs) {
			rs = "p" + count + "      ";
			count2 = 0;
			while (count2 < resources) {
				rs = rs + requestfromresource[count][count2] + "       ";
				count2++;
			}
			rs = rs + "        ";
			count2 = 0;
			while (count2 < resources) {
				rs = rs + unitsofeachresource[count][count2] + "       ";
				count2++;
			}
			count2 = 0;
			rs = rs + "        ";
			while (count2 < resources) {
				rs = rs + potential[count][count2] + "       ";
				count2++;
			}

			System.out.println(rs);
			count++;
		}

	}

	static void makeavailablearray() {
		available = new int[resources];

		int count = 0;
		int count2 = 0;
		int allocatedsum = 0;
		while (count < resources) {
			while (count2 < procs) {
				allocatedsum = allocatedsum + unitsofeachresource[count2][count];
				count2++;
			}

			allocatedsum = units[count] - allocatedsum;
			// System.out.println(units[count]);
			available[count] = allocatedsum;
			allocatedsum = 0;
			count2 = 0;
			count++;
		}

		// making potentail 2darray

		count = 0;
		count2 = 0;
		potential = new int[procs][resources];

		while (count < procs) {
			count2 = 0;
			while (count2 < resources) {
				potential[count][count2] = requestfromresource[count][count2] - unitsofeachresource[count][count2];

				count2++;
			}
			count++;
		}

	}

	static void growSize(String userdata) {

		// System.out.println(userdata);
		userdata.trim();
		// System.out.println(userdata);
		String[] data = userdata.split(" ");

		units = new int[resources];
		// for (String value : data) {
		// System.out.println(value);
		// }
		// System.out.println("inbound next prt and ur resources are a total of "+
		// resources);
		// This replaces any multiple spaces with a single space

		for (int index = 0; index < data.length; index++) {

			units[index] = Integer.parseInt(data[index].trim());

		}
	}

	static void dataimport2d(String userdata, int column, int which) {

		// System.out.println(userdata);
		userdata.trim();
		// System.out.println(userdata);
		String[] data = userdata.split(" ");

		// for (String value : data) {
		// System.out.println(value);
		// }
		// System.out.println("inbound next prt and ur resources are a total of "+
		// resources);
		// This replaces any multiple spaces with a single space

		for (int index = 0; index < data.length; index++) {

			if (which == 1)
				requestfromresource[column][index] = Integer.parseInt(data[index].trim());
			else if (which == 2)
				unitsofeachresource[column][index] = Integer.parseInt(data[index].trim());

		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		enterparams();
		bankersalgo();
		// System.out.println(Arrays.deepToString(potential).replace("], ", "]\n"));

		// pie a = new pie();
		// System.out.println(a.a);
	}

}
