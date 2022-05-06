using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using project.ViewModel;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace project.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class ExerciseListPage : ContentPage
    {
        public ExerciseListPage()
        {
            InitializeComponent();
            BindingContext = new ViewModel.ExerciseListViewModel();
        }
    }
}