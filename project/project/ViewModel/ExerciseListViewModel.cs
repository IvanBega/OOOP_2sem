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
        }
        public Command BackButtonCommand { get; set; }
        private void BackButtonClicked(object obj)
        {
            Application.Current.MainPage.Navigation.PopAsync();
        }
    }
}
