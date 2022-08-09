using System;
using System.Linq;
using System.Collections.Generic;

class Solution
{
    Dictionary<string, string> parking = new Dictionary<string, string>();  // 차 번호, 입차 시간
    Dictionary<string, int> totalTime = new Dictionary<string, int>();      // 차 번호, 총 시간
    Dictionary<string, int> receipt = new Dictionary<string, int>();        // 차 번호, 총 금액
    const string maxTime = "23:59";
    int[] fees;

    public List<int> solution(int[] fees, string[] records)
    {
        List<int> answer = new List<int>();
        this.fees = fees;

        for (int i=0; i<records.Length; i++)
        {
            string[] current = records[i].Split();

            if(!parking.TryAdd(current[1], current[0]))
                OutOfTheParking(current[1], current[0]);
        }

        foreach (string key in parking.Keys.ToList())
            OutOfTheParking(key, maxTime);

        foreach (string key in totalTime.Keys.ToList())
            Calculate(key);

        receipt = receipt.OrderBy(x => x.Key).ToDictionary(x=>x.Key, x=>x.Value);

        foreach (string key in receipt.Keys.ToList())
            answer.Add(receipt[key]);

        return answer;
    }

    void OutOfTheParking(string key, string outTime)    // 출차하여 총 시간 기록
    {
        int timeLag = GetTimeLag(outTime, parking[key]);
        parking.Remove(key);

        if(!totalTime.TryAdd(key, timeLag))
        {
            int prev = totalTime[key];
            totalTime.Remove(key);
            totalTime.Add(key, prev + timeLag);
        }
    }

    int GetTimeLag(string inTime, string outTime)       // 시간 차이 구하기
    {
        int[] inTimeArr = Array.ConvertAll(inTime.Split(':'), int.Parse);
        int[] outTimeArr = Array.ConvertAll(outTime.Split(':'), int.Parse);
        int timeLag = Math.Abs((outTimeArr[0] - inTimeArr[0]) * 60 + (outTimeArr[1] - inTimeArr[1]));

        return timeLag;
    }

    void Calculate(string key)                          // 정산
    {
        int total = fees[1];

        if (totalTime[key] > fees[0])
        {
            totalTime[key] -= fees[0];

            total += (int)Math.Ceiling(totalTime[key] / (double)fees[2]) * fees[3];
        }

        if (!receipt.TryAdd(key, total))
        {
            int prev = receipt[key];
            receipt.Remove(key);
            receipt.Add(key, prev + total);
        }
    }
}