using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;
using project.Views;
using project.Model;
using project.Repository;
namespace project.ViewModel
{
    public class MainViewModel : BaseViewModel
    {
        private readonly IRepository _repository;
        public static List<ExerciseModel> ExerciseList { get; set; }
        public MainViewModel(IRepository repository)
        {
            _repository = repository;
            ExerciseCommand = new Command(ExerciseClicked);
            ExerciseList = _repository.GetExerciseList();

        }
        public Command ExerciseCommand { get; set; }
        private void ExerciseClicked()
        {
            Application.Current.MainPage.Navigation.PushAsync(new ExerciseListPage());
            //Navigation
        }
        public static void AddExercise(string entry)
        {
            ExerciseModel newExercise = new ExerciseModel();
            newExercise.Name = entry;

            List<LogModel> newData = new List<LogModel>();
            LogModel data = new LogModel();
            data.Reps = 0;
            data.Sets = 0;
            data.Weights = 0;
            data.Date = DateTime.Now.ToString("dd/MM/yy");
            newData.Add(data);

            newExercise.Data = newData;

            ExerciseList.Add(newExercise);
            App.Current.MainPage.Navigation.PopToRootAsync();
            Application.Current.MainPage.Navigation.PushAsync(new Views.ExerciseListPage());
        }
        public static void RemoveExercise(ExerciseModel exercise)
        {
            ExerciseList.Remove(exercise);
            App.Current.MainPage.Navigation.PopToRootAsync();
            Application.Current.MainPage.Navigation.PushAsync(new Views.ExerciseListPage());

        }
        public static void AddLog(LogModel log, string exerciseName)
        {
            ExerciseModel exercise = null;
            foreach (ExerciseModel em in ExerciseList)
            {
                if (em.Name.Equals(exerciseName))
                {
                    exercise = em;
                    em.Data.Add(log);
                }
            }
            App.Current.MainPage.Navigation.PopToRootAsync();
            Application.Current.MainPage.Navigation.PushAsync(new Views.ExerciseListPage());
            Application.Current.MainPage.Navigation.PushAsync(new Views.Popups.ExercisePage((exercise)));
        }
    }
}
