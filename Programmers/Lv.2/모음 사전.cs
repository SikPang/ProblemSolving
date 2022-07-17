using System.Text;

public class Solution
{
    StringBuilder sb = new StringBuilder();
    string[] myWords = { "A", "E", "I", "O", "U" };
    int answer = 0;
    string word;
    bool isBreaked = false;

    public int solution(string word)
    {
        this.word = word;

        Find(0);

        return answer;
    }

    void Find(int depth)
    {
        if (word.Equals(sb.ToString()))
        {
            isBreaked = true;
            return;
        }

        if (depth == 5)
            return;

        for (int i=0; i<myWords.Length; i++)
        {
            sb.Append(myWords[i]);

            answer++;

            Find(depth + 1);

            if (isBreaked) return;

            sb.Remove(sb.Length - 1, 1);
        }
    }
}