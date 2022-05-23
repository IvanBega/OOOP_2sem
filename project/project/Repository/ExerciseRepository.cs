using project.Model;
using System;
using System.Collections.Generic;
using System.Text;
namespace project.Repository
{
    public class ExerciseRepository : IRepository
    {
        public List<ExerciseModel> GetExerciseList()
        {
            ExerciseModel model = new ExerciseModel();
            LogModel logModel = new LogModel();
            logModel.Date = "01/01/22";
            logModel.Reps = 0;
            logModel.Sets = 0;
            logModel.Weights = 0;
            var logModelList = new List<LogModel>();
            logModelList.Add(logModel);
            model.Data = logModelList;
            model.Name = "Exercise 1";

            var list = new List<ExerciseModel>();
            list.Add(model);
            model.Name = "Exercise 2";
            list.Add(model);
            return list;
        }
    }
}
