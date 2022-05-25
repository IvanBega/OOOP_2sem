using project.Model;
using Rg.Plugins.Popup.Contracts;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Text;
using Xamarin.Forms;

namespace project.ViewModel
{
    public class ExerciseViewModel : BaseViewModel
    {
        private string title = "Title test";
        private IPopupNavigation _popup { get; set; }
        public ObservableCollection<LogModel> LogList { get; set; }
        //public Command BackButtonCommand {get; set; }
        public Command AddLogCommand { get; set; }
        public string Title
        {
            get { return title; }
            set { title = value; NotifyPropertyChanged(); }
        }
        public Command BackButtonCommand;
        public ExerciseViewModel(ExerciseModel content)
        {
            Title = content.Name;
            BackButtonCommand = new Command(BackButtonClicked);
            foreach (LogModel lm in content.Data)
                LogList.Add(lm);

        }

        private void BackButtonClicked(object obj)
        {
            Application.Current.MainPage.Navigation.PopAsync();
        }
    }
}
