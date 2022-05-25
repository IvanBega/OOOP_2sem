using project.Model;
using project.ViewModel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace project.Views.Popups
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class ExercisePage : ContentPage
    {
        public ExercisePage(object content)
        {
            InitializeComponent();
            BindingContext = new ExerciseViewModel(content as ExerciseModel);
        }
    }
}