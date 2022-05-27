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
        public static List<ExerciseModel> ExerciseList { get; set; } = new List<ExerciseModel>();
        public MainViewModel()
        {
            //_repository = repository;
            ExerciseCommand = new Command(ExerciseClicked);
            InitializeList();

        }
        private async void InitializeList()
        {
            ExerciseRepository database = await ExerciseRepository.Instance;
            ExerciseList = database.GetItemsAsync();
        }
        public Command ExerciseCommand { get; set; }
        private void ExerciseClicked()
        {
            Application.Current.MainPage.Navigation.PushAsync(new ExerciseListPage());
            //Navigation
        }
        public async static void AddExercise(string entry)
        {
            ExerciseModel newExercise = new ExerciseModel();
            newExercise.Name = entry;

            List<LogModel> newData = new List<LogModel>();
            LogModel data = new LogModel();
            //data.Reps = 1;
            //data.Sets = 1;
            //data.Weights = 1;
            //data.Date = DateTime.Now.ToString("dd/MM/yy");
            //newData.Add(data);

            newExercise.Data = newData;

            ExerciseList.Add(newExercise);
            ExerciseRepository database = await ExerciseRepository.Instance;
            database.SaveItem(newExercise);
            await App.Current.MainPage.Navigation.PopToRootAsync();
            await Application.Current.MainPage.Navigation.PushAsync(new Views.ExerciseListPage());

        }
        public async static void RemoveExercise(ExerciseModel exercise)
        {
            ExerciseRepository database = await ExerciseRepository.Instance;
            ExerciseList.Remove(exercise);
            database.DeleteItem(exercise);
            await App .Current.MainPage.Navigation.PopToRootAsync();
            await Application .Current.MainPage.Navigation.PushAsync(new Views.ExerciseListPage());

        }
        public async static void AddLog(LogModel log, string exerciseName)
        {
            ExerciseModel exercise = null;
            foreach (ExerciseModel em in ExerciseList)
            {
                if (em.Name.Equals(exerciseName))
                {
                    ExerciseRepository database = await ExerciseRepository.Instance;
                    database.DeleteItem(em);

                    exercise = em;
                    em.Data.Add(log);
                    
                    database.SaveItem(em);
                }
            }
            await App.Current.MainPage.Navigation.PopToRootAsync();
            await Application.Current.MainPage.Navigation.PushAsync(new Views.ExerciseListPage());
            await Application.Current.MainPage.Navigation.PushAsync(new Views.Popups.ExercisePage((exercise)));
        }
    }
}
