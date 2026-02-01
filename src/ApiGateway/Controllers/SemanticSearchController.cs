using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;
using System.IO;

namespace ApiGateway.Controllers
{
    [ApiController]
    [Route("api/search")]
    public class SemanticSearchController : ControllerBase
    {
        [HttpGet]
        public IActionResult Search([FromQuery] string query)
        {
            // 1. Validate input
            if (string.IsNullOrWhiteSpace(query))
                return BadRequest("Query cannot be empty");

            // 2. Resolve path to C++ runtime executable
           var exePath = Path.GetFullPath(
    Path.Combine(
        AppContext.BaseDirectory,
        "..", "..", "..", "..", "..",
        "build",
        "windows_ai_runtime.exe"
    )
);

if (!System.IO.File.Exists(exePath))
{
    return StatusCode(500, $"Runtime executable not found at: {exePath}");
}

            // 3. Start C++ runtime process
            var psi = new ProcessStartInfo
            {
                FileName = exePath,
                Arguments = $"--search \"{query}\"",
                RedirectStandardOutput = true,
                RedirectStandardError = true,
                UseShellExecute = false,
                CreateNoWindow = true
            };

            using var process = Process.Start(psi);
            if (process == null)
                return StatusCode(500, "Failed to start runtime process");

            string output = process.StandardOutput.ReadToEnd();
            string error = process.StandardError.ReadToEnd();
            process.WaitForExit();

            if (process.ExitCode != 0)
                return StatusCode(500, $"Runtime error: {error}");

            // 4. Return response
            return Ok(new
            {
                query,
                result = int.Parse(output.Trim())
            });
        }
    }
}
