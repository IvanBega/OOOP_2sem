using Rg.Plugins.Popup.Services;
using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;

namespace project.ViewModel
{
    public class LogPopupViewModel
    {
        private double EntryReps1 = 0;
        private double EntryWeights1 = 0;
        private double EntryReps2 = 0;
        private double EntryWeights2 = 0;
        public string LogDate { get; set; }
        public Command BackButtonCommand { get; set; }
        public LogPopupViewModel()
        {
            LogDate = DateTime.Now.ToString("dd/MM/yy");
            BackButtonCommand = new Command(BackButtonClicked);
        }

        private async void BackButtonClicked()
        {
            await PopupNavigation.Instance.PopAsync();
        }
    }
}
