import java.io.*;
import java.util.*;

public class CalculateStatistics {

	public static void main(String[] args) throws IOException {
		ArrayList<Float> startupValues = new ArrayList<Float>();
		BufferedReader reader = new BufferedReader(new FileReader(args[0]));
		
		String line = reader.readLine();
		while (line != null) {
			float value = Float.parseFloat(line);
			
			startupValues.add(value);
			
			line = reader.readLine();
		}
		reader.close();
		
		// Calculate the statistics
		int count = 0;
		float sum = 0.0f;
		float mean = 0.0f;
		float max = 0.0f; float min = Float.MAX_VALUE;
		for (int i = 0; i < startupValues.size(); i++) {
			float value = startupValues.get(i);
		
			sum += value;
			++count;
			
			if (value > max) {
				max = value;
			}
			if (value < min) {
				min = value;
			}
		}
		mean = sum / count;
		
		float stdDev = 0.0f;
		float differenceMean2 = 0.0f;
		for (int i = 0; i < startupValues.size(); i++) {
			float value = startupValues.get(i);
			
			float difference2 = (float)Math.pow(value - mean, 2.0);
			differenceMean2 += difference2;
		}
		differenceMean2 /= count;
		stdDev = (float)Math.sqrt(differenceMean2);
		
		// Print out the stats
		System.out.println("Total # of Executions: " + count);
		System.out.printf("Total Startup Time: %.1fms\n", sum * 1000);
		System.out.printf("Average Startup Time: %.1fms\n", mean * 1000);
		System.out.printf("Startup Time Standard Deviation: %.1fms\n", stdDev * 1000);
		System.out.printf("Min Startup Time: %.1fms\n", min * 1000);
		System.out.printf("Max Startup time: %.1fms\n", max * 1000);
	}

}
