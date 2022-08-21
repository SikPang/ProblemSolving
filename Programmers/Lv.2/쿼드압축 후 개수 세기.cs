public class Solution
{
    int[] answer = new int[2];
    int[,] arr;

    public int[] solution(int[,] arr)
    {
        this.arr = arr;

        Quad(0, 0, arr.GetLength(0));

        return answer;
    }

    void Quad(int x, int y, int size)
    {
        if (Check(x, y, size))
        {
            answer[arr[x, y]]++;
            return;
        }
        else
        {
            size /= 2;

            Quad(x, y, size);
            Quad(x + size, y, size);
            Quad(x, y + size, size);
            Quad(x + size, y + size, size);
        }
    }

    bool Check(int x, int y, int size)
    {
        for (int i = x; i < x + size; i++)
            for (int j = y; j < y + size; j++)
                if (arr[i, j] != arr[x, y])
                    return false;

        return true;
    }
}