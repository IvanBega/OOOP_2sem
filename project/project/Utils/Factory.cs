using System;
using System.Collections.Generic;
using System.Text;
using project.Repository;
namespace project.Utils
{
    public static class Factory
    {
        public static IRepository CreateRepository()
        {
            return new ExerciseRepository();
        }
    }
}
