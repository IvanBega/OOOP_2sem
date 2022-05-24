using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;

namespace project.ViewModel
{
    public class ExerciseViewModel : BaseViewModel
    {
        private string title;
        public string Title
        {
            get { return title; }
            set { title = value; NotifyPropertyChanged(); }
        }
        public Command BackButtonCommand;
        public ExerciseViewModel()
        {
            BackButtonCommand = new Command(BackButtonClicked);
        }

        private void BackButtonClicked(object obj)
        {
            Application.Current.MainPage.Navigation.PopAsync();
        }
    }
}
