using System;

class Solution
{
    int[] answer = new int[11];
    int[] curShot = new int[11];
    int[] info;
    int n;
    int apeachScore;
    int maxScore = 0;
    int curScore = 0;

    public int[] solution(int n, int[] info)
    {
        this.info = info;
        this.n = n;
        for (int i = 0; i < info.Length; i++)
        {
            if (info[i] > 0)
                apeachScore += 10 - i;
        }

        Shot(0);

        if (maxScore == 0)
            return new int[] { -1 };
        else
            return answer;
    }

    void Shot(int depth)
    {
        if (depth == n)
        {
            CheckHighScore();
            return;
        }

        for (int i = 0; i < 11; i++)
        {
            if (curShot[i] > info[i] || n - depth < info[i] + 1) continue;

            GetScore(i);

            Shot(depth + curShot[i]);

            LossScore(i);
        }

        if (n - depth > 0)
        {
            curShot[10] += n - depth;
            CheckHighScore();
            curShot[10] -= n - depth;
        }
    }

    void CheckHighScore()
    {
        if (curScore > apeachScore && curScore - apeachScore >= maxScore)
        {
            if (curScore - apeachScore == maxScore)
            {
                bool isBreaked = false;

                for (int i = answer.Length - 1; i >= 0; i--)
                {
                    if (answer[i] > curShot[i]) return;
                    else if (answer[i] < curShot[i])
                    {
                        isBreaked = true;
                        break;
                    }
                }

                if (!isBreaked) return;
            }

            maxScore = curScore - apeachScore;
            Array.Copy(curShot, 0, answer, 0, 11);
        }
    }

    void GetScore(int i)
    {
        curShot[i] += info[i] + 1;
        curScore += 10 - i;
        if (info[i] > 0)
            apeachScore -= 10 - i;
    }

    void LossScore(int i)
    {
        curShot[i] = 0;
        curScore -= 10 - i;
        if (info[i] > 0)
            apeachScore += 10 - i;
    }
}