import org.junit.Test;

public class MinMaxArrayTest {

    int[] array = new int[] {1, 2, 3, 58, 47, 229, 40};

    @Test
    public void shouldBeMaxValue() {
        int maxValue = MinMaxArray.getMaxValue(array);
        assert(maxValue == 229);
    }

    @Test
    public void shouldBeMinValue() {
        int minValue = MinMaxArray.getMinValue(array);
        assert(minValue == 1);
    }

    @Test(expected = IllegalArgumentException.class)
    public void shouldBeIllegalArgumentException() {
        int[] emptyArray = new int[] {};
        int maxValue = MinMaxArray.getMaxValue(emptyArray);
        int minValue = MinMaxArray.getMinValue(emptyArray);
    }
}