public class Solution
{
    int[,] arr;
    int[,] queries;
    int[] answer;

    public int[] solution(int rows, int columns, int[,] queries)
    {
        this.queries = queries;
        answer = new int[queries.GetLength(0)];
        arr = new int[rows, columns];
        int count = 0;

        for (int i = 0; i < arr.GetLength(0); i++)
            for (int j = 0; j < arr.GetLength(1); j++)
                arr[i, j] = ++count;

        for (int i = 0; i < queries.GetLength(0); i++)
            answer[i] = Rotate(i);

        return answer;
    }

    int Rotate(int index)
    {
        int temp = arr[queries[index, 0]-1, queries[index, 3] - 1];
        int min = temp;

        for (int i = queries[index, 3] - 1; i > queries[index, 1] - 1; --i)
        {
            min = Math.Min(min, arr[queries[index, 0] - 1, i]);
            arr[queries[index, 0] - 1, i] = arr[queries[index, 0] - 1, i - 1];
        }

        for (int i = queries[index, 0] - 1; i < queries[index, 2] - 1; ++i)
        {
            min = Math.Min(min, arr[i, queries[index, 1] - 1]);
            arr[i, queries[index, 1] - 1] = arr[i + 1, queries[index, 1] - 1];
        }

        for (int i = queries[index, 1] - 1; i < queries[index, 3] - 1; ++i)
        {
            min = Math.Min(min, arr[queries[index, 2] - 1, i]);
            arr[queries[index, 2] - 1, i] = arr[queries[index, 2] - 1, i + 1];
        }

        for (int i = queries[index, 2] - 1; i > queries[index, 0] - 1; --i)
        {
            min = Math.Min(min, arr[i, queries[index, 3] - 1]);
            arr[i, queries[index, 3] - 1] = arr[i - 1, queries[index, 3] - 1];
        }

        arr[queries[index, 0], queries[index, 3] - 1] = temp;

        return min;
    }
}