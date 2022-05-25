using project.Model;
using project.Views.Popups;
using Rg.Plugins.Popup.Contracts;
using Rg.Plugins.Popup.Services;
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
        private LogPopup _logPage;
        public string Title
        {
            get { return title; }
            set { title = value; NotifyPropertyChanged(); }
        }
        public Command BackButtonCommand;
        public ExerciseViewModel(ExerciseModel content)
        {
            _logPage = new LogPopup();
            _popup = PopupNavigation.Instance;
            Title = content.Name;
            LogList = new ObservableCollection<LogModel>();
            BackButtonCommand = new Command(BackButtonClicked);
            foreach (LogModel lm in content.Data)
                LogList.Add(lm);
            AddLogCommand = new Command(AddLogClicked);

        }

        private async void AddLogClicked(object obj)
        {
            await _popup.PushAsync(_logPage);
        }

        private void BackButtonClicked(object obj)
        {
            Application.Current.MainPage.Navigation.PopAsync();
        }
    }
}
