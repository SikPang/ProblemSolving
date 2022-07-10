using System.Text;

class Test
{
    static StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
    static StringBuilder sbTemp = new StringBuilder();
    static StringBuilder sbAnswer = new StringBuilder();
    static List<int> indexList = new List<int>();
    static string[] vowel = { "a", "e", "i", "o", "u" };
    static string[] strs;
    static bool[] isVowel;
    static int max;

    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());

        int[] nums = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);
        strs = sr.ReadLine().Split();
        isVowel = new bool[strs.Length];
        max = nums[0];

        Array.Sort(strs);
        for(int i=0; i<strs.Length; i++)
        {
            if (vowel.Contains(strs[i]))
                isVowel[i] = true;
            else
                isVowel[i] = false;
        }

        FindPassword(0, 0);

        sw.Write(sbAnswer.ToString());
        sw.Close();
    }

    static void FindPassword(int depth, int index)
    {
        if (depth == max)
        {
            if (!CheckCorrect()) return;

            sbAnswer.AppendLine(sbTemp.ToString());

            return;
        }

        for(int i=index; i<strs.Length; i++)
        {
            sbTemp.Append(strs[i]);
            indexList.Add(i);

            FindPassword(depth + 1, i + 1);

            sbTemp.Remove(sbTemp.Length - 1, 1);
            indexList.RemoveAt(indexList.Count - 1);
        }
    }

    static bool CheckCorrect()
    {
        int vowelCnt = 0;
        int consonantCnt = 0;

        for (int i=0; i<indexList.Count; i++)
        {
            if(isVowel[indexList[i]])
                vowelCnt++;
            else
                consonantCnt++;
        }

        if (vowelCnt >= 1 && consonantCnt >= 2)
            return true;
        else
            return false;
    }
}