using System;
using System.Collections.Generic;
using System.Text;

namespace project.Model
{
    public class LogModel
    {
        public string Date { get; set; }
        public float Weights { get; set; }
        public float Sets { get; set; } // кількість підходів
        public float Reps { get; set; } // кількість повторів в одному підході
    }
}
