using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using project.Model;

namespace project.Repository
{
    public interface IRepository
    {
        List<ExerciseModel> GetAllItems();
        void SaveItem(ExerciseModel item);
        void DeleteItem(ExerciseModel item);
    }
}
