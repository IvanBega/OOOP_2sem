using Microcharts;
using project.Model;
using project.Views.Popups;
using Rg.Plugins.Popup.Contracts;
using Rg.Plugins.Popup.Services;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Text;
using Xamarin.Forms;
using SkiaSharp;
using System.Globalization;

namespace project.ViewModel
{
    public class ExerciseViewModel : BaseViewModel
    {
        private string title = "Title test";
        private IPopupNavigation _popup { get; set; }
        public ObservableCollection<LogModel> LogList { get; set; }
        public Command BackButtonCommand {get; set; }
        public Command AddLogCommand { get; set; }
        private LogPopup _logPage;
        private Chart _chart;
        public string Title
        {
            get { return title; }
            set { title = value; NotifyPropertyChanged(); }
        }
        public Chart Chart
        {
            get { return _chart; }
            set { _chart = value; NotifyPropertyChanged(); }
        }
        public ExerciseViewModel(ExerciseModel content)
        {
            _logPage = new LogPopup(content.Name);
            _popup = PopupNavigation.Instance;
            //content.Data.Sort(SortByDate);
            Title = content.Name;
            LogList = new ObservableCollection<LogModel>();
            BackButtonCommand = new Command(BackButtonClicked);
            foreach (LogModel lm in content.Data)
                LogList.Add(lm);
            AddLogCommand = new Command(AddLogClicked);

            List<ChartEntry> entries = LoadGraph();
            Chart = new LineChart()
            {
                Entries = entries,
                MinValue = 0,
                LabelOrientation = Orientation.Horizontal,
                ValueLabelOrientation = Orientation.Horizontal,
                LineMode = LineMode.Straight,
                PointMode = PointMode.Square,
                LabelTextSize = 36,
                LineSize = 6,
            };



        }

        private async void AddLogClicked(object obj)
        {
            await _popup.PushAsync(_logPage);
        }

        private void BackButtonClicked(object obj)
        {
            Application.Current.MainPage.Navigation.PopAsync();
        }

        private List<ChartEntry> LoadGraph()
        {
            List<ChartEntry> entries = new List<ChartEntry>();

            foreach(LogModel lm in LogList)
            {
                int value = (int)(lm.Reps * lm.Sets * lm.Weights);
                ChartEntry e = new ChartEntry(value)
                {
                    ValueLabel = value.ToString(),
                    Label = lm.Date
                };
                entries.Add(e);
            }

            return entries;
        }
        int SortByDate(LogModel a, LogModel b)
        {
            DateTime a1 = DateTime.ParseExact(a.Date, "dd/MM/yy", CultureInfo.InvariantCulture);
            DateTime b1 = DateTime.ParseExact(b.Date, "dd/MM/yy", CultureInfo.InvariantCulture);
            return a1.CompareTo(b1) * -1;
        }
    }
}
