using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;

namespace project.ViewModel
{
    public class ExerciseListViewModel
    {
        public ExerciseListViewModel()
        {
            BackButtonCommand = new Command(BackButtonClicked);
            AddExerciseCommand = new Command(AddButtonClicked);
            RemoveExerciseCommand = new Command(RemoveButtonClicked);
        }

        private void RemoveButtonClicked(object obj)
        {
            throw new NotImplementedException();
        }

        private void AddButtonClicked(object obj)
        {
            throw new NotImplementedException();
        }

        public Command BackButtonCommand { get; set; }
        public Command AddExerciseCommand { get; set; }
        public Command RemoveExerciseCommand { get; set; }
        private void BackButtonClicked(object obj)
        {
            Application.Current.MainPage.Navigation.PopAsync();
        }
    }
}
