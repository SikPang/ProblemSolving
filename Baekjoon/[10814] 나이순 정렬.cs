using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();
        List<Person> list = new List<Person>();

        int num = int.Parse(sr.ReadLine());

        for (int i = 0; i < num; i++)
        {
            string[] str = sr.ReadLine().Split();
            list.Add(new Person { age = int.Parse(str[0]), name = str[1] });
        }

        foreach (Person person in list.OrderBy(i => i.age))
        {
            sb.AppendLine(person.age + " " + person.name);
        }

        sw.Write(sb.ToString());
        sw.Close();
    }

    class Person
    {
        public int age;
        public string name;
    }
}