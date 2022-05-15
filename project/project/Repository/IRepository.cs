using System;
using System.Collections.Generic;
using System.Text;
using project.Model;

namespace project.Repository
{
    public interface IRepository
    {
        List<ExerciseModel> GetExerciseList();
    }
}
