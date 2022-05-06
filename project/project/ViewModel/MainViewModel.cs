using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;
using project.Views;
namespace project.ViewModel
{
    public class MainViewModel : BaseViewModel
    {
        public MainViewModel()
        {
            ExerciseCommand = new Command(ExerciseClicked);

        }
        public Command ExerciseCommand { get; set; }
        private void ExerciseClicked()
        {
            Application.Current.MainPage.Navigation.PushAsync(new ExerciseListPage());
            //Navigation
        }
    }
}
